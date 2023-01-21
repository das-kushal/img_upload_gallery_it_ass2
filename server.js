const express = require('express')
const multer = require("multer")
const uuid = require('uuid').v4
const path = require('path')
const fs = require('fs')

const uploadsDir = 'uploads/';

const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, 'uploads')
    },
    filename: (req, file, cb) => {
        const { originalname } = file
        cb(null, `${uuid()}-${originalname}`)
    }
})



const upload = multer({ storage })

const app = express()
app.use(express.static('public'))

app.post("/upload", upload.single('myfile'), (req, res) => {
    console.log('File is uploaded');
    res.sendFile(path.join(__dirname) + '/public/success.html')
})


app.get('/files', (req, res) => {
    fs.readdir(uploadsDir, (err, files) => {
        if (err) {
            res.status(500).send(err);
        } else {
            const fileList = files.map((file) => {
                return {
                    name: file,
                    path: `/preview/${file}`,
                };
            });
            res.json(fileList);
        }
    });
});

app.get('/preview/:file', (req, res) => {
    const file = req.params.file;
    const filePath = path.join(__dirname, 'uploads', file);
    res.sendFile(filePath);
});

app.get('/download/:file', (req, res) => {
    const file = req.params.file;
    const filePath = path.join(__dirname, 'uploads', file);
    res.download(filePath);
});


app.listen(3001, () => { console.log('Server is listening on port 3001'); });



