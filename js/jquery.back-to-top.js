(function ($) {
  Drupal.behaviors.to_the_top= {
    attach: function (context, settings) {
      $("#back-to-top").hide();
      $(window).scroll(function () {
        if ($(this).scrollTop() > 100) {
          $('#back-to-top').fadeIn();
          $('body').toggleClass('fixed');
        } else {
          $('#back-to-top').fadeOut();
          $('body').toggleClass('fixed');
        }
      });
      $('#back-to-top').click(function () {
        $('body,html').animate({
          scrollTop: 0
        }, 800);
        return false;
      });
    }
  };
})(jQuery);

