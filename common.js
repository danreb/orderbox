// JavaScript Document
(function($) {
   $(document).ready(function(){
   // utility function add, remove
     function add() {
     if($(this).val() == ''){
       $(this).val($(this).attr('placeholder')).css('color', 'gray');
         }
       }

     function remove() {
     if($(this).val() == $(this).attr('placeholder')){
       $(this).val('');
          }
       }

        // Detect if placeholder is not supported
     if (!('placeholder' in $('<input>')[0])) {
   
        // Select the elements that have a placeholder attribute
        $('input[placeholder]').blur(add).focus(remove).each(add);
    
        // Remove the placeholder text before the form is submitted
        $('form').submit(function(){
      $(this).find('input[placeholder]').each(remove);
          });
      
        }
    });
  
})(jQuery);