
var canHit = true;


var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

app.get('/', function(req, res){
	if(canHit){
		console.log("hit!");
		io.sockets.emit('timeline', "true");
		canHit = false;
		setTimeout(function(){ canHit = true; }, 1000);
	}else{
		console.log("on cooldown");
	}
	res.send(':)');
});

io.on('connection', function(socket){
	console.log('a user connected');
});


http.listen(8000, function(){
	console.log('listening on *:8000');
});
