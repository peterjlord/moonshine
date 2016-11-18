(function ($) {
  Drupal.behaviors.localnav= {
    attach: function (context, settings) {
			$('ul.tabs-horizontal', context).once('localnavigation').each(function(context) {
        localnavigation(context);
			});
    }
  };
	function localnavigation(context) {
		$(".tabs-horizontal").addClass('js');
		$("ul.tabs-horizontal li:first-child").prepend( "<span class='toggle-p'>Toggle</span>"   );
		$(".toggle-p").click(function() {
      $('.tabs-horizontal.js').toggleClass('clicked')
		});
	}
})(jQuery);

