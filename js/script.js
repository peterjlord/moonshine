(function ($) {
	Drupal.behaviors.moonshine= {
		attach: function (context, settings) {
			// Click to expand search.
		/*
    $('#search-block-form').submit(function (e) {
      var $header = $(this).parents('#nav-header');
      if (!$header.hasClass('search-expanded')) {
        $header.addClass('search-expanded');
        this.querySelector('input[type="text"]').focus();
        e.preventDefault();
      }
    }).find('input').blur(function () {
      // Wait for next element to gain focus.
      setTimeout(function () {
        var trigger = document.querySelector('#nav-header.search-expanded');
        // Check if focused element is still in the expanded menu.
        if (trigger !== null && !trigger.querySelector('#search-block-form').contains(document.activeElement)) {
          trigger.classList.remove('search-expanded');
        }
      }, 150);
    });
    // Skip to search a11y link.
    $('.skip-link-search').click(function (e) {
      $('#search-block-form').submit();
      e.preventDefault();
    });
		*/
		}
 	};
})(jQuery);
