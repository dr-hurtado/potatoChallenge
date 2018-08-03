// Requires

var io = require('socket.io')({
	transports: ['websocket'],
});

// Setting
io.attach(4567);


// Sockets
io.on('connection', function(socket){

	socket.on('ready', function(){
		socket.emit('adelante');
	});

})
