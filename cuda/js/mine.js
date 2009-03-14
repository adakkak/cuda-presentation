$(function(){
    $(".content").append("<strong>It verks</strong>");
    $.getJSON("pres.json",
      function(data){
	$.each(data.items, function(i,item){
		 $("<li>").text(item.content.title).appendTo("ul.slides");
	       });
      });

});
