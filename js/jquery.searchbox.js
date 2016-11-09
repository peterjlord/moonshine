(function ($,  Drupal, window) {
 'use strict';

	Drupal.behaviors.searchbox= {
		attach: function (context, settings) {
			$('#search-block-form', context).once('searchbox').each(function(context) {
				searchBox(context);
			});
		}
 	};
	function searchBox(context) {
		$('#search-block-form').submit(function (e) {
			var $header = $(this).parents('header.centered-navigation');
			if (!$header.hasClass('search-expanded')) {
      	$header.addClass('search-expanded');
        this.querySelector('input[type="search"]').focus();
				e.preventDefault();
			} 
		}).find('input').blur(function () {
			setTimeout(function () {
        var trigger = document.querySelector('header.centered-navigation .search-expanded');
				if (trigger !== null && !trigger.querySelector('#search-block-form').contains(document.activeElement)) {
          trigger.classList.remove('search-expanded');
				}
			}, 150);
		});
	}
})(jQuery, Drupal, window);
