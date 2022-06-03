const mongoose = require('mongoose');

const Image = new mongoose.Schema({
  title: String,
  content: {
    data: Buffer,
    contentType: String
  },
});

module.exports = mongoose.model('Image', Image);
