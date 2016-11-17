#pragma once
#ifndef PEERING_STATS
#define PEERING STATS 1

#include <ctime>
#include <chrono>
#include <string>
#include <boost/circular_buffer.hpp>

class c_data_tramsmission_buffer{
    public:
        c_data_tramsmission_buffer(int buffer_size, int interval_in_milisec);
        void update_sent_buffer(std::size_t data_size);
        void update_read_buffer(std::size_t data_size);
        double get_current_sent_speed() const;
        double get_current_read_speed() const;
        std::string get_data_buffer_as_js_str(std::string var);
        std::string get_speed_as_js_str(std::string var);
        std::string get_packets_buffer_as_js_str(std::string var);
        std::string get_charts_as_js_str(std::string var, bool display_big_chart);

    private:
        boost::circular_buffer<int> m_data_sent_buffer;
        boost::circular_buffer<int> m_data_read_buffer;
        boost::circular_buffer<int> m_packets_sent_buffer;
        boost::circular_buffer<int> m_packets_read_buffer;
        long m_last_sent;
        long m_last_read;
        int m_interval;
        std::chrono::time_point<std::chrono::system_clock> m_reference_time;
};

class c_peering_stats{
    public:
        c_peering_stats();
        void update_sent_stats(std::size_t size_of_sent_data);
        void update_read_stats(std::size_t size_of_read_data);
        std::size_t get_size_of_sent_data() const;
        std::size_t get_size_of_read_data() const;
        double get_current_sent_speed() const;
        double get_current_read_speed() const;
        long get_number_of_sent_packets() const;
        long get_number_of_read_packets() const;
        std::string get_connection_time() const;
        void reset_connection_time();
        c_data_tramsmission_buffer & get_data_buffer();

    private:
        std::size_t m_size_of_sent_data;
        std::size_t m_size_of_read_data;
        long m_number_of_sent_packets;
        long m_number_of_read_packets;
        std::chrono::time_point<std::chrono::system_clock> m_connection_time;
        c_data_tramsmission_buffer m_data_buffer;
};

#endif
