require("dotenv").config();

const config = {
  dev: process.env.NODE_ENV,
  port: process.env.PORT,
  dbLocal: process.env.MONGODB_URI,
  authAdminUsername: process.env.AUTH_ADMIN_USERNAME,
  authAdminPassword: process.env.AUTH_ADMIN_PASSWORD,
  authAdminEmail: process.env.AUTH_ADMIN_EMAIL,
  authJwtSecret: process.env.AUTH_JWT_SECRET
};

module.exports = { config };
