var bodyParser = require('body-parser');
var express = require("express");
var app = express();
var port = 8000;
var url='localhost'
var server = app.listen(port);
var io = require("socket.io").listen(server);
var serialport = require("serialport");
var SerialPort = serialport.SerialPort;

var Parse= require('node-parse-api').Parse;
var APP_ID="9fcAEhI6Bb5ZGmSjZAnscI2GOpxBtcg7zTzc0fz4";
var MASTER_KEY = "6VuiFWq0eAW773dTS7tPINbsG47RJif2DUjICbF2";
var appParse = new Parse(APP_ID, MASTER_KEY);
var io = require("socket.io").listen(server);

var sport = new SerialPort("/dev/ttyAMA0", {
  baudrate: 9600,
  parser: serialport.parsers.readline("\n")
}, false); 

app.use(express.static(__dirname + '/'));
console.log('Simple static server listening at '+url+':'+port);

app.get('', function (req, res) {
  res.setHeader('Content-Type', 'text/plain; charset=utf-8')
  res.end('YOUR SERVER IS RUNNING')

})

process.on('uncaughtException', function (exception) {
   // handle or ignore error
  });


io.sockets.on('connection', function (socket) {
sport.open(function(error) {

  if (error) {
    console.log('failed to open: ' + error);
  } else {
    sport.write("A");
    console.log('Serial open');
    sport.on('data', function(data) {
    //console.log('data length: ' + data.length);
      
    result = data;

 appParse.insert('tree', { NUMBERS: result}, function (err, response) {
    //console.log(response);
//     console.log("INSERTED");


appParse.find('tree', '', function (err, response) {
  //console.log(response);
  // console.log("FOUND");
// socket.on('getFromParse', function (data) {
//     appParse.find('WootWoot', '', function (err, response) {
//   console.log(response);
//   socket.emit('toScreen',{ ParseData: response });
// });
   for (var i = 0; i < response.results.length; i++) {
     console.log(response.results[i].NUMBERS);
      socket.emit(response.results[i].NUMBERS);
       //socket.emit('tree',{ ParseData: response });
       
   };

//for (int thisPin = 2; thisPin < 8; thisPin++) { 

   // console.log(response.results.length);

});


 });

    

 //     appParse.delete('tree', '', function (err, response) {
 // console.log(response);
// });

 });

  
    // console.log(data);
    // console.log("You sent R=" + data.r + " G="+ data.g + " B="+ data.g);
   // socket.emit('toScreen', { r: result[1], g: result[2], b: result[3] });    
    //socket.emit('toScreen', {data});   
  



    
    // port.write("A");
  


}


//INSERT OBJECT






  
});
});






//socket.io stuff
// io.sockets.on('connection', function (socket) {
//   socket.on('toColor', function (data) {
//     console.log(data);
//     console.log("You sent R=" + data.r + " G="+ data.g + " B="+ data.g);
//     socket.emit('toScreen', { r: data.r, g: data.g, b: data.b });     

//   });
// });