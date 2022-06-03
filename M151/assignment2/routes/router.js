const express = require('express');
const multer = require('multer');
const {db} = require('../db/client');
const router = express.Router();
const Post = require('../models/Post')
const Image = require('../models/Image')

const upload = multer({ storage: multer.memoryStorage() })

router.get('/', (req, res) => {
  res.render('index', { title: 'Home', back_btn: false });
});


// BLOG

router.get('/blog', async (req, res) => {
  const posts = await Post.find({}) // empty filter = all
  res.render('blog', { title: 'Awesomeness Blog', back_btn: true, posts: posts })
})

router.get('/blog/:id', async (req, res) => {
  const postId = req.params.id
  const post = await Post.findOne({ _id: postId }) // empty filter = all
  res.render('blog-single', { title: 'Awesomeness Blog', back_btn: true, post: post })
})

router.get('/blog-post', (req, res) => {
  res.render('blog-post', { title: 'Create Blog Post', back_btn: true, action: '/blog-post', is_edit: false })
})

router.get('/blog-post/edit/:id', async (req, res) => {
  const postId = req.params.id
  const post = await Post.findOne({ _id: postId })
  console.log("edit", post)
  res.render('blog-post', { title: 'Create Blog Post', back_btn: true, action: `/blog-post/${postId}`, post: post, is_edit: true })
})

router.post('/blog-post', async (req, res) => {
  const postTitle = req.body['post-title']
  const postContent = req.body['post-content']
  await Post.create({ title: postTitle, content: postContent })
  res.redirect('/blog');
});

router.post('/blog-post/:id', async (req, res) => {
  const postId = req.params.id
  const postTitle = req.body['post-title']
  const postContent = req.body['post-content']
  await Post.updateOne({ _id: postId }, { title: postTitle, content: postContent })
  res.redirect(`/blog/${postId}`)
})

router.get('/blog-post/delete/:id', async (req, res) => {
  const postId = req.params.id
  await Post.deleteOne({ _id: postId })
  res.redirect('/blog')
})


// IMAGE
router.get('/image', async (req, res) => {
  const images = await Image.find({})
  res.render('image', { title: 'Your Images', back_btn: true, images: images })
});

router.get('/image-upload', (req, res) => {
  res.render('image-upload', { title: 'Upload Images', back_btn: true, action: '/image-upload', is_edit: false })
});

router.post('/image-upload', upload.single('image-content'), async (req,res) => {
  const imageTitle = req.body['image-title']
  await Image.create({
    title: imageTitle,
    content: {
      data: req.file.buffer,
      contentType: req.file.mimetype
    }
  })
  res.redirect('/image')
})

router.get('/image-upload/edit/:id', async (req, res) => {
  const imageId = req.params.id
  const image = await Image.findOne({ _id: imageId })
  res.render('image-upload', { title: 'Upload Images', back_btn: true, action: `/image-upload/edit/${imageId}`, image: image, is_edit: true })
});

router.post('/image-upload/edit/:id', upload.single('image-content'), async (req, res) => {
  const imageId = req.params.id
  const imageTitle = req.body['image-title']
  let obj = {}
  if (req.file) {
    obj = {
      title: imageTitle,
      content: {
        data: req.file.buffer,
        contentType: req.file.mimetype
      }
    }
  } else {
    obj = {
      title: imageTitle
    }
  }
  await Image.updateOne({ _id: imageId }, obj)
  res.redirect('/image')
})

router.get('/image/delete/:id', async (req, res) => {
  const imageId = req.params.id
  await Image.deleteOne({ _id: imageId })
  res.redirect('/image')
})

module.exports = router;
