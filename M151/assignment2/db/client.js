const mongoose = require('mongoose');
require('dotenv').config();

mongoose.connect(process.env.MONGODB_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

let db = mongoose.connection
db.on('error', console.error.bind(console, 'MongoDB connection error:'));

module.exports = {
    db
}
