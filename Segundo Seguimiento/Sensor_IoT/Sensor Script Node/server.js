const fs = require("fs")
const postService = require("./services/postService")

var stat = 0;

async function postStat() {
    const PostService = new postService()
    setInterval(async () => {
        let rawdata = fs.readFileSync('../Sensor Server C/sensor_log.json');
        let student = JSON.parse(rawdata);
        data = student.data[student.data.length - 1]
        if (stat != data.Stamp) {
            console.log(student.data[student.data.length - 1]);
            await PostService.createPost(data)
            stat = data.Stamp
        }
    }, 500)
}


postStat()