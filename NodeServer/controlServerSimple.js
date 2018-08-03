// Requires
var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM0', {
//var port = new SerialPort('COM3', {
    baudRate: 9600
});

var io = require('socket.io')({
	transports: ['websocket'],
});

// Setting
io.attach(4567);


// Sockets
io.on('connection', function(socket){

    console.log("start Server");

	socket.on('ready', function(){
		socket.emit('start');
	});

    socket.on('from', function(){
        console.log("Adelante");
        port.write('w');
    });

    socket.on('stop', function(){
        console.log("stop");
        port.write('f');
    });

    socket.on('back', function(){
        console.log("back");
        port.write('s');
    });

    socket.on('right', function(){
        console.log("right");
        port.write('d');
    });

    socket.on('left', function(){
        console.log("left");
        port.write('a');
    });

    socket.on('open', function(){
        console.log("open");
        port.write('g');
    });

    socket.on('close', function(){
        console.log("close");
        port.write('h');
    });

    socket.on('up', function(){
        console.log("up");
        port.write('j');
    });

    socket.on('down', function(){
        console.log("down");
        port.write('k');
    });

});
