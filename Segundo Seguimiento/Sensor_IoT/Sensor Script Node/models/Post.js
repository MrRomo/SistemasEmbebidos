const {Schema, model} = require('mongoose')
const {ObjectId} = Schema

const StatSchema = new Schema ({
    ID: {type: String}, 
    Temp: {type: Number}, 
    Tum: {type: Number},
    Stamp: {type: Number},
    Date: {type: Date, default: Date.now}
})

module.exports = model('Stat', StatSchema)