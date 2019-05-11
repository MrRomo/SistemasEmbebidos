const mongoose = require('mongoose')
const { config } = require("../config");
const USER = encodeURIComponent(config.dbUser);
const PASSWORD = encodeURIComponent(config.dbPassword);
const DB_NAME = config.dbName;
const chalk = require('chalk')
const MONGO_URI = config.dbLocal; // prettier-ignore

class MongoLib {
  constructor() {
    console.log('Connecting db...');
    mongoose.connect(MONGO_URI, {
      useCreateIndex: true,
      useNewUrlParser: true,
      useFindAndModify: false
    })
      .then(db => console.log(`DB is connected to: ${MONGO_URI}`))
      .catch(err => console.error(err))
  }
  async get(query, Schema) {
    let Data = await Schema.findOne(query)
    return Data
  }
  async getAll(query, Schema, Params) {
    let Data = await Schema.find(query)
    .sort(Params.sort)
    .limit(Params.limit)
    return Data
  }
  async create(object, Schema) {
    let Data = new Schema (object)
    const saveData = await Data.save()
    return saveData
  }
  async update(object, Schema){    
    console.log(chalk.magenta.bold('Update mongo'),object)    
    const update = await Schema.updateOne(object.query,object.options,object.array||{})
    return update
  }
  async delete(query, Schema) {
    try{
      await Schema.deleteMany(query)
      return {message: 'All deleted'}
    }catch(eer){
      return err
    }
  }


}

module.exports = MongoLib;
