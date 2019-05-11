const multer = require('multer');
const path = require('path')
const awsWorker = require('../services/awsWorker');

var storage = multer.memoryStorage()

const config = multer({
  dest: path.join(__dirname, '../public/upload/temp'),
  limits: { fileSize: 6000000 },
  fileFilter: (req, file, cb) => {
    const filetypes = /jpeg|jpg|png/;
    const mimetype = filetypes.test(file.mimetype)
    const extname = filetypes.test(path.extname(file.originalname).toLowerCase())
    if (mimetype && extname) {
      return (cb(null, true))
    } else {
      cb({ message: "ERROR: El archivo debe ser una imagen valida" })
    }
  }
}).array('image', 8)

module.exports = config 