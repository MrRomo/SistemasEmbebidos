'use strict';

const fs = require('fs');

let rawdata = fs.readFileSync('sensor_log.json');  
let student = JSON.parse(rawdata);  
console.log(student);  
console.log(student.data[student.data.length-1]);  
