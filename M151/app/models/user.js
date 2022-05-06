var mongoose = require('mongoose');
var passportLocalMongoose = require('passport-local-mongoose')

var UserScheme = new mongoose.Schema({
	username: String,
	password: String,
    phone: String,
});
UserScheme.plugin(passportLocalMongoose)

module.exports = new mongoose.model('User', UserScheme);
