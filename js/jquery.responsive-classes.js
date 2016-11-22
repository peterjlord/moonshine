(function ($) {
  Drupal.behaviors.responsive_classes= {
    attach: function (context, settings) {
      $('html', context).once('response_classes').each(function(context) {
        responsive_classes(context);
      });
    }
  };
  function responsive_classes(context) {
		// Put the jquery here
		$(document).ready(function(){
    	responsive_set_classes();
		});
		// Change width value on user resize, after DOM
		$(window).resize(function(){
     responsive_set_classes();
		});	
  }
	function responsive_set_classes() {
		var current_width = $(window).width();
		
		if(current_width < 481)
      $('html').addClass("m320").removeClass("m768").removeClass("desktop").removeClass("m480");

    else if(current_width < 739)
      $('html').addClass("m768").removeClass("desktop").removeClass("m320").removeClass("tablet");

    else if (current_width < 970)
      $('html').addClass("tablet").removeClass("desktop").removeClass("m320").removeClass("m768");

    else (current_width > 971)
      $('html').addClass("desktop").removeClass("m320").removeClass("m768").removeClass("tablet");
	}
})(jQuery);
