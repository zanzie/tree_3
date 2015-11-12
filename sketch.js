var yoff = 0.0;        // 2nd dimension of perlin noise
var socket;

function setup() {
  createCanvas(1710, 1000);
  //socket = io.connect('http://192.168.1.135:8000');

}

function draw() {

//io.sockets.on('connection', function (data) {
// console.log(data);
//socket.emit(response.results[i].NUMBERS);
// console.log(response.results[i].NUMBERS);
 // background(11);
noFill();
  fill(height-(random(100)/(mouseY/4)),mouseX/6,mouseY/4,3);
  //noStroke();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  
  stroke(random(250),random(50));
  
  // We are going to draw a polygon out of the wave points
  beginShape(width/2, height/2); 
  
  var xoff = 0;       // Option #1: 2D Noise
  // float xoff = yoff; // Option #2: 1D Noise
  
  // Iterate over horizontal pixels
  for (var x = 0; x <= width; x += 10) {
    // Calculate a y value according to noise, map to 
    
    // Option #1: 2D Noise
    var y = map(noise(xoff, yoff), 0, 1, 200,300) - 400;

    // Option #2: 1D Noise
    // float y = map(noise(xoff), 0, 1, 200,300);
    
    // Set the vertex
    vertex((x - mouseX) - map(noise(xoff), 0, 1, 200,300), y + map(noise(xoff), 0, 1, 200,300) + mouseY); 
    // Increment x dimension for noise
    xoff += 0.25;
  }
  // increment y dimension for noise
  yoff += 0.01;
  vertex(mouseX, mouseY - map(noise(xoff), 0, 1, 200,900));
  vertex(mouseX - random(30), height + random(30));
  endShape(mouseX, height + mouseY);
fill(random(255),random(255),random(255),5);
rect(random(width),random(height),random(30)+10,random(30)+10);
ellipse(random(width),random(height),random(30)+10,random(30)+10);
rect(random(width),random(height),random(30)+30,random(30)-10);
};
//rect(0,0,width,height);


//}