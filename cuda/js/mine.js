$(function(){
    $.getJSON("pres.json",
      function(data){
	$.each(data.items, function(i,item){
		 $("<li class=\"title\">")
		   .text(item.content.title)
		   .appendTo("ul.slides");
	       });
      });

});
