// Requires

var io = require('socket.io')({
	transports: ['websocket'],
});

// Setting
io.attach(4567);


// Sockets
io.on('connection', function(socket){

	socket.on('ready', function(){
		socket.emit('start');
	});

    socket.on('from', function(){
        console.log("Adelante");
    });

    socket.on('back', function(){
        console.log("back");
    });
})
