#include "CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

#define test_yandex_ssl

#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",587);
		mail.SetSecurityType(CSmtp::USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",465);
		mail.SetSecurityType(CSmtp::USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(CSmtp::USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(CSmtp::USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(CSmtp::USE_SSL);
#elif defined(test_yandex_ssl)
		mail.SetSMTPServer("smtp.yandex.ru",465);
		mail.SetSecurityType(CSmtp::USE_SSL);

#elif defined(test_yandex_no_security)
		mail.SetSMTPServer("smtp.yandex.ru",25);
		mail.SetSecurityType(CSmtp::NO_SECURITY);
//		mail.SetSecurityType(CSmtp::USE_TSL);
#endif

		mail.SetLogin("borev.borev");
		mail.SetPassword("borevborev");
  		mail.SetSenderName("борев");
  		mail.SetSenderMail("borev.borev@yandex.ru");
  		mail.SetReplyTo("borev.borev@yandex.ru");
  		mail.SetSubject("сообщение");
  		mail.AddRecipient("borev.borev@yandex.ru");
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine("Здрасте,");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("фыфывафывафывафыва?");
		mail.AddMsgLine("");
		mail.AddMsgLine("фывафывафыва");
		mail.ModMsgLine(5,"regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("фывафываф");
		
  		//mail.AddAttachment("../test1.jpg");
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
