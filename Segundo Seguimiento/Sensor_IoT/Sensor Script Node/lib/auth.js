module.exports = {
    isLoggedIn(req, res, next) {
        if (req.isAuthenticated()) {
            return next()
        } else {
            // return next()
            return res.redirect('/signin')
        }
    },
    isNotLoggedIn(req, res, next) {
        if (req.isAuthenticated()) {
            // return next()
            return res.redirect('/home')
        } else {
            return next()
        }
    },
    async isAdmin(req, res, next) {        
        if (req.user.admin) {
            return next()
        } else {
            return res.redirect('/home')
        }
    },

}