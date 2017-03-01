

#include "transport/email/transp_email_obj.hpp"

#include "libs1.hpp"

c_transport_email_obj::~c_transport_email_obj() {
}

void c_transport_email_obj::send_to(const c_transport_base_addr & dest, const unsigned char *data, size_t size) {
	_check(size>=1);

	auto email = (boost::any_cast<c_transport_email_addr::t_addr>( dest.get_addrdata() ));
	_info("Tranport send to " << email << " data: " <<  to_debug( std::string(data , data+size) , e_debug_style_buf ) );

	volatile char fake;
	size_t pos=0;
	pos += data[1];
	if (size>=2) pos += data[2]*256;
	if (size>=3) pos += data[2]*256*256;
	fake = data[ pos % size ]; // force a fake "write" to volatile (compiler can't predict what part, it must provide entire data[]
}



