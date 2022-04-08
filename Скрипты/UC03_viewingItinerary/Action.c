Action()
{

	lr_start_transaction("UC03_viewingItinerary");
	
	
	
	lr_start_transaction("openHomePage");

	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	
	web_reg_save_param("userSession",
		"LB=name=\"userSession\" value=\"",
		"RB=\"",
		LAST);
		
	web_reg_find("Text/IC=Web Tours",LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("openHomePage",LR_AUTO);

	
	
	lr_start_transaction("login");
	
	lr_think_time(5);

	web_reg_find("Text/IC=User password was correct",LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=67", ENDITEM,
		"Name=login.y", "Value=2", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
	

	lr_start_transaction("clickItinerary");

	lr_think_time(5);
	
	web_reg_find("Text/IC=User wants the intineraries",LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("clickItinerary",LR_AUTO);

	
	
	lr_start_transaction("signOff");

	lr_think_time(5);
	
	web_reg_find("Text/IC=A Session ID has been created and loaded into a cookie called MSO",LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signOff",LR_AUTO);
	
	
	
	lr_end_transaction("UC03_viewingItinerary", LR_AUTO);

	return 0;
}