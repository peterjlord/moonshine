var gulp = require('gulp');
var compass = require('gulp-compass');
var shell   = require('gulp-shell');

gulp.task('compass', function() {
  gulp.src(['./sass/*.scss', './sass/lib/*.scss'])
    .pipe(compass({
      config_file: './config.rb',
      css: 'css',
      sass: 'sass'
      }))
     .on('error',console.log.bind(console)) //Error handling and 
    .pipe(gulp.dest('css'));
});
gulp.task('clearcache', function() {
  return shell.task([
    'drush cc all'
  ]);
});

gulp.task('watch', function () {
  gulp.watch(['sass/*.scss', 'sass/**/*.scss'], ['compass']);
});


gulp.task('default', ['watch']);

