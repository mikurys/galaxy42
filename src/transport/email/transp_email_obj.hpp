
#pragma once

#include "libs0.hpp"

#include "transport/base/transp_base_obj.hpp" // parent
#include "transport/email/transp_email_addr.hpp" // own addr

class c_transport_email_obj : public c_transport_base_obj {
	public:
		virtual ~c_transport_email_obj();
		virtual void send_to(const c_transport_base_addr & dest, const unsigned char *data, size_t size) override;

	protected:
		c_transport_email_addr m_addr; ///< my own address
};



