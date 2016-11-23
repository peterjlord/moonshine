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
		$("ul.tabs-horizontal li:first-child").before( '<li class="first"></li>');
		$("ul.tabs-horizontal li.is-active a").click( function (event) {
			event.preventDefault();
      $('.tabs-horizontal.js').toggleClass('clicked')
			}).dblclick(function() {
    		window.location.replace($(this).attr("href"));
			});;
	}
})(jQuery);

