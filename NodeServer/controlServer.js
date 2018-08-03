// Requires
var gpio = require('rpi-gpio');
var io = require('socket.io')({
	transports: ['websocket'],
});

// Setting
io.attach(4567);
var isEmiting = true;
gpio.setup(7, gpio.DIR_OUT, write);

console.log("Start Server");

// GPIO
function write(err) {
    if (err) throw err;
    gpio.write(7, true, function(err) {
        if (err) throw err;
        console.log('Written to pin');
    });
}

gpio.on('change', function(channel, value) {
    console.log('Channel ' + channel + ' value is now ' + value);
});
gpio.setup(11, gpio.DIR_IN, gpio.EDGE_BOTH);


// Sockets
io.on('connection', function(socket){

	socket.on('ready', function(){
		socket.emit('button1');
		console.log("Sending");
		isEmiting = (!isEmiting) ? true : false;
		gpio.write(7, isEmiting);
	});

})
