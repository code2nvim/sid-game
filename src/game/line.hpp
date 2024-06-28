#ifndef SID_LINE_HPP
#define SID_LINE_HPP

namespace Sid {

    class Line {
        Line();
        ~Line() = default;
        Line(const Line&) = delete;
        Line& operator=(const Line&) = delete;
        Line(Line&&) noexcept = delete;
        Line& operator=(Line&&) noexcept = delete;
    };

}

#endif // SID_LINE_HPP
