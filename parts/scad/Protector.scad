use <raid3r/raid3r.scad>


module screw(d){
translate([0,0,-5])rotate([0,0,0])union(){
cylinder(r=5.3/2, h=6, $fn=10);
cylinder(r=2.9/2, h=6+d, $fn=10);
}
}



module bbbholes(z){
union(){
translate([0,0,0])screw(30);
translate([0,41.85,0])screw(30);

translate([0,-3.1,0]){
translate([65.8,0,0])screw(30);
translate([65.8,48.2,0])screw(30);
}

}

}

module interruptor(){
translate([0,14,-10])cylinder(r=2.5,h=20,$fn=20);
translate([0,7.5,-10])cylinder(r=1.2,h=20,$fn=20);
translate([0,-7.5,-10])cylinder(r=1.2,h=20,$fn=20);
cube([4,8,20], center=true);

}



difference(){
union(){

	difference(){
translate([-51,6,0])cube([102,59,5]);
		translate([-49,4,3])cube([98,59,20]);
}


	


}
		translate([-43,44,0])interruptor();
		cylinder(r=4,h=20,$fn=20)

		translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
		mirror([1,0,0])translate([-10-51,-12,-5])rotate([0,0,-20])cube([20,20,80]);
		translate([-15-19,12,0])bbbholes(6);



	}


