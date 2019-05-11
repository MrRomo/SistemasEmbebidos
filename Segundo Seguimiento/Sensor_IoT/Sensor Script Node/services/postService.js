const MongoLib = require("../lib/mongo");
const Post = require('../models/Post')
const chalk = require('chalk')

class postService {
  constructor() {
    this.collection = "posts";
    this.mongoDB = new MongoLib();
    console.log(chalk.green.bold('Connect Mongo'))    
  }

  async getPost(query) {
    const post = await this.mongoDB.get(query, Post)
    return post || {};
  }
  async getPosts(query) {
    const params = {
      sort: { date: -1 },
      limit: 10
    }
    const posts = await this.mongoDB.getAll(query, Post, params)
    return posts || [];
  }
  async createPost(object) {
    const post = await this.mongoDB.create(object, Post)
    return post || {};
  }
}

module.exports = postService