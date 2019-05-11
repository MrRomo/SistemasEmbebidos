const passport = require('passport')
const LocalStrategy = require('passport-local')
const { User } = require('../models')
const Mongolib = require('./mongo')

passport.use(new LocalStrategy({
  usernameField: 'username'
}, async (username, password, done) => {
  // Match Email's User
  const query = { username: username.toLowerCase() }
  const mongo = new Mongolib()
  let user = await mongo.get(query, User)
  if (!user) {
    return done(null, false, { message: 'Username not found.' });
  } else {
    // Match Password's User
    const match = await user.matchPassword(password)
    if (match) {
      user.lastSign = Date.now()
      await user.save()
      return done(null, user, { message: 'Bienvenido ' + user.fullname });
    } else {
      return done(null, false, { message: 'Incorrect Password.' });
    }
  }
}));


passport.serializeUser((user, done) => {
  done(null, user.id);
});

passport.deserializeUser((id, done) => {
  User.findById(id, (err, user) => {
    done(err, user);
  });
});