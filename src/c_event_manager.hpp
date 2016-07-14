#ifndef C_EVENT_MANAGER_HPP
#define C_EVENT_MANAGER_HPP

#include "c_tun_device.hpp"
#include "c_udp_wrapper.hpp"

class c_event_manager {
	public:
		virtual ~c_event_manager() = default;
		virtual void wait_for_event() = 0;
		virtual bool receive_udp_paket() = 0;
		virtual bool get_tun_packet() = 0;
};

#ifdef __linux__
class c_tun_device_linux;
class c_udp_wrapper_linux;
#include <sys/select.h>
class c_event_manager_linux final : public c_event_manager {
	public:
		c_event_manager_linux(const c_tun_device_linux &tun_device, const c_udp_wrapper_linux &udp_wrapper);
		void wait_for_event();
		bool receive_udp_paket();
		bool get_tun_packet();
	private:
		const int m_tun_fd;
		const int m_udp_socket;
		fd_set m_fd_set_data; ///< select events e.g. wait for UDP peering or TUN input
};
#else
class c_tun_device_empty;
class c_udp_wrapper_empty;
class c_event_manager_empty final : public c_event_manager {
	public:
		c_event_manager_empty(const c_tun_device_empty &tun_device, const c_udp_wrapper_empty &udp_wrapper);
		void wait_for_event();
		bool receive_udp_paket();
		bool get_tun_packet();
};
#endif // __linux__

#endif // C_EVENT_MANAGER_HPP
