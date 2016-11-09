'use strict';

var gulp = require('gulp');
var compass = require('gulp-compass');
var shell   = require('gulp-shell');
var svgSymbols = require('gulp-svg-symbols');


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

gulp.task('icons', function () {
	return gulp.src('./images/svg-inuse/*.svg')
		.pipe(svgSymbols({
			svgClassname: 'svg-icon-lib',
			title: '%f Icon',
			slug: function (name) {
    		return name.replace(/-/g, '').replace(/[0-9]/g, '');
			},
			transformData: function(svg, defaultData, options) {
				return {
    			// Return every datas you need 
    			id:         defaultData.id,
    			className:  defaultData.className,
    			width:      32 + 'px',
    			height:     32 + 'px'
				};
			}
	}))
  .pipe(gulp.dest('./images/'));
});

gulp.task('watch', function () {
  gulp.watch(['sass/*.scss', 'sass/**/*.scss', 'images/svg-inuse/*.svg'], ['compass', 'icons']);
});


gulp.task('default', ['watch']);

