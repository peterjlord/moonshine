(function ($) {
	Drupal.behaviors.moonshine= {
		attach: function (context, settings) {
			// Click to expand search.
    $('#search-block-form').submit(function (e) {
			
      var $header = $(this).parents('header.centered-navigation');
      if (!$header.hasClass('search-expanded')) {
        $header.addClass('search-expanded');
        this.querySelector('input[type="text"]').focus();
        e.preventDefault();
      }
    }).find('input').blur(function () {
      // Wait for next element to gain focus.
      setTimeout(function () {
        var trigger = document.querySelector('header.search-expanded');
        // Check if focused element is still in the expanded menu.
        if (trigger !== null && !trigger.querySelector('#search-block-form').contains(document.activeElement)) {
          trigger.classList.remove('search-expanded');
        }
      }, 150);
    });
		}
 	};
})(jQuery);
