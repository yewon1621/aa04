var express = require('express');
var app = express();
var port = 3030;

var path = require('path');

app.get('/', function(req, res) {
    res.send("<a href='/hello'>Hello Page</a>");
});

app.get('/hello', function(req, res) {
    res.send('Hello aa04');
});

app.get('/comsi', function(req, res) {
    res.send('Hello Comsi!');
});

app.use(express.static(path.join(__dirname, 'public')));

var server = app.listen(port, function(){
    console.log("Listning on port %d", server.address().port);
});