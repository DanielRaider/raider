#include "raider.h"

using namespace std;
using namespace cv;
using namespace zbar;

Raider::Raider(){

//Javi del futuro, echa un ojo a esto
//ofstream Serial ("/sys/devices/bone_capemgr.9/slots");
//ofstream ADC("/sys/devices/bone_capemgr.9/slots");

    report(INFO, "Wake up Raider!");

//SERIAL COMMUNICATION
    report("Setting serial communication...");
    serial = new Serial();
    int serial_flag=serial->Open(SERIAL_PORT, BAUD_RATE); // TODO revisar bool char
    if (serial_flag==1) report(OK, "Serial communication connected!");
    else if (serial_flag==-2)report(ERROR, "Serial communication failed (at opening device)");
    else if (serial_flag==-4)report(ERROR, "Serial communication failed (check baud rate)");
    else report(ERROR, "Serial communication failed (unknown error)");

//I2C BUS CONNECTION
    report("Setting I2C bus...");
    i2c = new I2C(I2C_BUS);
    if (i2c->test(0x00)) report(OK, "I2C bus connected!"); // TODO revisar
    else report(ERROR, "I2C doesn't work!");

//IMU SENSOR
    report("Setting imu sensor...");
    imu = new IMU(i2c);
    if(4294967295==imu->getAccelerometerX()) report(ERROR, "IMU sensor connection FAILED");
    else if(65535==imu->getAccelerometerX()) report(WARNING, "Accelerometer may be not working (please check)");
    else report(OK, "IMU sensor connected!");

//COMPASS SENSOR
    report("Setting compass sensor...");
    compass = new Compass(i2c);
    setCompassTolerance(180);
    report(OK, "Compass sensor connected!");

//INFRARRED SENSORS
    report("Setting infrarred sensors...");
    if(getAIN(0)<=0) report(ERROR, "Error in infrarred sensors (pin 0)");
    else if(getAIN(1)<=0) report(ERROR, "Error in infrarred sensors (pin 1)");
    else report(OK,"Infrarred sensors are working fine!");

//CAMERA
    report("Setting camera...");
    camera = new VideoCapture(CAMERA_ID);
    if(!camera->isOpened()) report(ERROR, "Camera failed at opening, wrong device id?");
    else report(OK, "Camera initialized");
}

int Raider::getLeftIR(){
    for(int i=0; i<8; i++) leftIR=getAIN(AIN5); //Para vaciar el buffer
    if(leftIR>INFRARED_HIGH)return 2;
    else if(leftIR>INFRARED_LOW)return 1;
    return 0;
}

int Raider::getRightIR(){
    for(int i=0; i<8; i++) rightIR=getAIN(AIN3); //Para vaciar el buffer
    if(rightIR>INFRARED_HIGH)return 2;
    else if(rightIR>INFRARED_LOW)return 1;
    return 0;
}

int Raider::getCompass(){
    return compass->getCompass();
}

void Raider::setCompassTolerance(int data){
    compass_tolerance=data;
}

int Raider::getFall(){
    int ay=imu->getAccelerometerY()*360/65355;
    if(ay<=90&&ay>FALL_DEGREES){
        return 1;
    }
    else if(ay>=270&&ay<360-FALL_DEGREES){
        return 2;
    }
    else{
        return 0; //Derecho
    }
}

bool Raider::walk(){
    char command= 'W';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (walk)");
        return 0;
    }
    usleep(WALK);
    return 1;
}

bool Raider::run(){
    char command= 'S';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (run)");
        return 0;
    }
    usleep(RUN);
    return 1;
}

bool Raider::getUp(){ // TODO revisar comando

    int error;
    char command;
    int state_vertical=getFall();
    if (state_vertical==0) return 1;
    else if (state_vertical==1){
        report(INFO, "FRONT fall  > ");
        command='U';
        error=serial->WriteChar(command);
        if (error==-1){
            report(WARNING,"Failed sending command (standUp)");
            return 0;
        }
        usleep(GETUP);
    }
    else if (state_vertical==2){
        report(INFO, "BACK  fall  < ");
        command='R';
        error=serial->WriteChar(command);
        if (error==-1){
            report(WARNING,"Failed sending command (roll)");
            return 0;
        }
        usleep(ROLL);
        command='U';
        error=serial->WriteChar(command);
        if (error==-1){
            report(WARNING,"Failed sending command (getup)");
            return 0;
        }
        usleep(GETUP);
        return 1;
    }
}

bool Raider::turnL(){
    char command= 'A';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (turnLeft)");
        return 0;
    }
    usleep(TURNL);
    return 1;
}

bool Raider::turnR(){
    char command= 'D';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (turnRight)");
        return 0;
    }
    usleep(TURNR);
    return 1;
}

bool Raider::stepL(){
    char command= 'Q';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (stepLeft)");
        return 0;
    }
    usleep(STEPL);
    return 1;
}

bool Raider::stepR(){
    char command= 'E';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (stepRight)");
        return 0;
    }
    usleep(STEPR);
    return 1;
}

bool Raider::roll(){
    char command= 'R';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (roll)");
        return 0;
    }
    usleep(ROLL);
    return 1;
}

bool Raider::yes(){
    char command= 'Y';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (yes)");
        return 0;
    }
    usleep(YES);
    return 1;
}

bool Raider::punchL(){
    char command='Z';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (punchL)");
        return 0;
    }
    usleep(PUNCHL);
    return 1;
}

bool Raider::punchR(){
    char command='B';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (punchR)");
        return 0;
    }
    usleep(PUNCHR);
    return 1;
}

bool Raider::crab(){
    char command='C';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (crab)");
        return 0;
    }
    usleep(CRAB);
    return 1;
}

bool Raider::miniPunchL(){
    char command='X';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (miniPunchL)");
        return 0;
    }
    usleep(MINIPUNCHL);
    return 1;
}

bool Raider::miniPunchR(){
    char command='V';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (miniPunchR)");
        return 0;
    }
    usleep(MINIPUNCHR);
    return 1;
}

bool Raider::defense(){
    char command='w';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (defense)");
        return 0;
    }
    usleep(DEFENSE);
    return 1;
}

bool Raider::lookL(){
    char command='a';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (lookL)");
        return 0;
    }
    usleep(LOOKL);
    return 1;
}

bool Raider::lookR(){
    char command='d';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (lookR)");
        return 0;
    }
    usleep(LOOKR);
    return 1;
}

bool Raider::look(){
    char command='L';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (look)");
        return 0;
    }
    usleep(LOOK);
    return 1;
}

bool Raider::lookUp(){
    char command='l';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (look)");
        return 0;
    }
    usleep(LOOKUP);
    return 1;
}

bool Raider::endLookUp(){
    char command='f';
    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command (look)");
        return 0;
    }
    usleep(ENDLOOKUP);
    return 1;
}


bool Raider::sendCommand(char command){

    int error=serial->WriteChar(command);
    if (error==-1){
        report(WARNING,"Failed sending command");
        return 0;
    }
    return 1;
}

Mat Raider::getFrame(){
    for(int i=0; i<5; i++) camera->grab(); // TODO quizas haya alguna forma mas elegante TODO
    Mat frame;
    camera->read(frame);
    return frame;
}

Vec2i Raider::findWay(Mat image){

    Mat1b input=detectGreen(image);
    standardShow(input,"tras detect green");
    //imshow("Frame", image );
    Mat map=input.clone();

    threshold(input, input, 50 , 255, THRESH_BINARY);

    input=dilation(input,20);
    input=dilation(input,-10);

    //DIBUJAR LINEAS
    for (int i=0;i<input.rows;i++) input.at<uchar>(i,0)=0;
    for (int i=0;i<input.rows;i++) input.at<uchar>(i,input.cols-1)=0;

    Mat output=input.clone();

    zhangSuen(output);

    standardShow(output,"zhangsuen");
    vector<vector<Point> > contours;
    findContours(output.clone(), contours,CV_RETR_LIST,CV_CHAIN_APPROX_NONE);

    int way=0;
    Point top_max(0,output.rows);
    Point bot_max(0,0);
    Point mid_max;
    bool way_flag=false;
    if(contours.empty())return 'Z';
    for(int i=0; i<contours.size(); i++){
        Point top(0,output.rows);
        Point bot(0,0);

        for(int j=0; j<contours.at(i).size(); j++){
            if(contours.at(i).at(j).y<top.y){
                top=contours.at(i).at(j);
            }
            if(contours.at(i).at(j).y>bot.y){
                bot=contours.at(i).at(j);
            }

        }
        if((top.y<top_max.y)&&(bot.y>output.rows*0.9)){
            way=i;
            way_flag=true;
            top_max=top;
            bot_max=bot;
        }
    }

    for(int j=0; j<contours.at(way).size(); j++){
        if(contours.at(way).at(j).y>output.rows*0.8&&contours.at(way).at(j).y<output.rows*0.9){
            mid_max=contours.at(way).at(j);
        }
    }

    float x=mid_max.x-bot_max.x;
    float y=bot_max.y-mid_max.y;
    float alfa;
    int d=-output.cols/2+bot_max.x;

    report("Distance to way: "+to_string(d));
    if(x==0) alfa=0;
    else alfa=atan(x/y)*180/3.1415927;
    report("Way angle: "+to_string(alfa));

    drawLine(output,bot_max,mid_max); //debug
    //drawLine(output,Point(output.cols/2-20,output.rows),
    //                Point(output.cols/2+20,output.rows)); //debug
    showMap(map,output); //debug

    return Vec2i(d,alfa);
}


Vec2i Raider::findLine(Mat frame){

    Rect rect(0,frame.rows/3,frame.cols,(frame.rows*2)/3); //Recortar a la mitad

    Mat image = frame(rect);
    Mat1b input=detectGreen(image);
    imshow("prim", input);


    Canny(input, input, 50, 200, 5);

    imshow("canny", input);

    input=dilation(input,8);
    input=dilation(input,-9);

    imshow("postcanny", input);

    //imshow("original",input);// debug

    vector<Vec4i> lines;
    HoughLinesP(input, lines, 1, CV_PI/180, 80,40, 30 );// TODO ajustar
    int max_length=0;
    int max_line=0;
    if(lines.size()>0){
        for( size_t i = 0; i < lines.size(); i++ )
        {
            Vec4i l = lines[i];
            int length=sqrt(pow((l[2]-l[0]),2)+pow((l[3]-l[1]),2));
            if(length>max_length){
                max_length=length;
                max_line=i;
            }
        }
        line( image,
              Point(lines.at(max_line)[0], lines.at(max_line)[1]),
                Point(lines.at(max_line)[2], lines.at(max_line)[3]),
                Scalar(255,0,0), 1, CV_AA);

        float y=lines.at(max_line)[2]-lines.at(max_line)[0];
        float x=lines.at(max_line)[3]-lines.at(max_line)[1];
        int alfa;
        if(y==0)alfa=90;
        else alfa=atan(x/y)*180/CV_PI;
        int d=input.rows-(lines.at(max_line)[3]+lines.at(max_line)[1])/2;

        report("Numero de lineas: "+to_string(lines.size()));
        report("La mas larga mide: "+to_string(max_length));
        report(INFO,"Linea a un angulo de: "+to_string(alfa));
        report(INFO,"A una distancia de: "+to_string(d));
        imshow("Resultado", image);
        Vec2i result(d,alfa);
        return result;
    }
    else return Vec2i(-1,0); //No hay linea
}

string Raider::findQR(Mat frame){

    ImageScanner scanner;
    scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);

    cvtColor(frame,frame,CV_BGR2GRAY);
    uchar *pointer = (uchar *)frame.data;

    Image image(frame.cols, frame.rows, "Y800", pointer, frame.cols*frame.rows);

    scanner.scan(image);

    string command;
    int distance;
    int distance_min=frame.cols/2;
    int i=0;

    for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
        distance=abs(symbol->get_location_x(i) - frame.cols/2);
        report("Marcador: "+to_string(symbol->get_data())+ "     Distance: "+to_string(distance));

        if(distance<distance_min){
            distance_min=distance;
            command=symbol->get_data();
        }
        i++;
    }
    if (!command.empty()) report (INFO,"Marcador: "+command+ "     Distance: "+to_string(distance));
    return command;
}

bool Raider::setDirection(bool side, int target_angle){
    //side 1 derecha
    //side 0 izquierda

    int min_range=target_angle-compass_tolerance;
    if (min_range<0) min_range+=3600;

    int max_range=target_angle+compass_tolerance;
    if (max_range>3600)max_range-=3600;

    int cont=0;
    int angle=getCompass();
    if(side==1){
        if(max_range>min_range){
            turnR();
            cont++;
            report("minimo: "+to_string(min_range)+"    Maximo: "+to_string(max_range));
            report("Angulo actual: "+to_string(angle)+"    Angulo objetivo: "+to_string(target_angle));
            angle=getCompass();
            if((angle>min_range)&&(angle<max_range)) return 1;
            else return 0;
        }

        else{
            turnR();
            cont++;
            report("minimo: "+to_string(min_range)+"    Maximo: "+to_string(max_range));
            report("Angulo actual: "+to_string(angle)+"    Angulo objetivo: "+to_string(target_angle));
            angle=getCompass();
            if((angle>min_range)||(angle<max_range)) return 1;
            else return 0;
        }
    }

    if(side==0){
        if(max_range>min_range){
            turnL();
            cont++;
            report("minimo: "+to_string(min_range)+"    Maximo: "+to_string(max_range));
            report("Angulo actual: "+to_string(angle)+"    Angulo objetivo: "+to_string(target_angle));
            angle=getCompass();
            if((angle>min_range)&&(angle<max_range)) return 1;
            else return 0;
        }

        else{
            turnL();
            cont++;
            report("minimo: "+to_string(min_range)+"    Maximo: "+to_string(max_range));
            report("Angulo actual: "+to_string(angle)+"    Angulo objetivo: "+to_string(target_angle));
            angle=getCompass();
            if((angle>min_range)||(angle<max_range)) return 1;
            else return 0;
        }
    }
}



bool Raider::setDirection(int target_angle){
    //side 1 derecha
    //side 0 izquierda
    bool side;

    int ref_angle=getCompass();

    int right_distance=target_angle-ref_angle;
    if (right_distance<0) right_distance+=3600;

    int left_distance=ref_angle-target_angle;
    if (left_distance<0) left_distance+=3600;

    if (right_distance<left_distance) side=1;
    else side=0;

    bool flag=setDirection(side,target_angle); // TODO comprobar si es posible
    return flag;
}

void Raider::waitStart(){

    bool wait=1;

    while(wait){
        Mat frame=getFrame();
        ImageScanner scanner;
        scanner.set_config(ZBAR_QRCODE, ZBAR_CFG_ENABLE, 1);

        cvtColor(frame,frame,CV_BGR2GRAY);
        uchar *pointer = (uchar *)frame.data;

        Image image(frame.cols, frame.rows, "Y800", pointer, frame.cols*frame.rows);
        scanner.scan(image);

        for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            if(symbol->get_data()== "GoRaider") wait=0;
        }
    }
    report(RAIDER,"ROGER ROGER!");
    yes();
}


