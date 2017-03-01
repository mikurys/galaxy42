#include "transport/email/transp_email_addr.hpp"


c_transport_email_addr::c_transport_email_addr(std::string email) : c_transport_base_addr(email) { }

void c_transport_email_addr::print(ostream & ostr) const {
	auto email = boost::any_cast<std::string>(get_addrdata());
	ostr << "[transp-email-" << email << "]" ;
}

