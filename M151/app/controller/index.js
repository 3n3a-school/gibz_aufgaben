const path = require('path')

function controller (req, res) {
	res.sendFile(path.resolve(__dirname, '../views/index.html'))
}

module.exports = {
    controller
}