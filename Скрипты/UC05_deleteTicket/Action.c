Action()
{

	lr_start_transaction("UC05_deleteTicket");

	
	
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
		"Name=login.x", "Value=82", ENDITEM,
		"Name=login.y", "Value=10", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
	

	lr_start_transaction("clickItinerary");

	lr_think_time(5);
	
	web_reg_find("Text/IC=User wants the intineraries",LAST);
	
	web_reg_save_param("flightID",
	"LB=name=\"flightID\" value=\"",
	"RB=\"",
	"Ord=ALL",
	LAST);

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
	
	

	lr_start_transaction("cancelChecked");

	lr_think_time(5);	
				
	if (atoi(lr_eval_string("{deleteNumber}")) == 1){
				
	web_reg_find("Fail=Found",
		"Text={flightID_1}",
		LAST);
	
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=33", ENDITEM,
		"Name=removeFlights.y", "Value=4", ENDITEM,
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);

			} 
	
	else if (atoi(lr_eval_string("{deleteNumber}")) == 2){
				
	web_reg_find("Fail=Found",
		"Text={flightID_1}",
		LAST);
		
	web_reg_find("Fail=Found",
		"Text={flightID_2}",
		LAST);
		
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=33", ENDITEM,
		"Name=removeFlights.y", "Value=4", ENDITEM,
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);
			
			} 
	
	else if (atoi(lr_eval_string("{deleteNumber}")) == 3){
				
	web_reg_find("Fail=Found",
		"Text={flightID_1}",
		LAST);
		
	web_reg_find("Fail=Found",
		"Text={flightID_2}",
		LAST);
		
	web_reg_find("Fail=Found",
		"Text={flightID_3}",
		LAST);
		
	web_submit_form("itinerary.pl",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=2", "Value=on", ENDITEM,
		"Name=3", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=33", ENDITEM,
		"Name=removeFlights.y", "Value=4", ENDITEM,
		EXTRARES,
		"URL=http://localhost:1080/cgi-bin/itinerary.pl",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", ENDITEM,
		LAST);
		
			}

	lr_end_transaction("cancelChecked",LR_AUTO);
	
	

	lr_start_transaction("signOff");

	lr_think_time(5);
	
	web_reg_find("Text/IC=A Session ID has been created and loaded into a cookie called MSO",LAST);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signOff",LR_AUTO);
	
	
	
	lr_end_transaction("UC05_deleteTicket", LR_AUTO);

	return 0;
}