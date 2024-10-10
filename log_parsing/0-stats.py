#!/usr/bin/python3
"""read and parse log data"""
import sys

line_count = 0
total_size = 0

status_codes = {
    200: 0,
    403: 0,
    404: 0,
    401: 0,
    405: 0,
    500: 0
}


def print_logs():
    """a function"""
    print("File size: {}".format(total_size))
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


try:
    while True:
        line = sys.stdin.readline()
        if not line:
            break

        line_count += 1
        try:
            data = line.split()
            if len(data) < 9:
                continue

            status = int(data[-2])
            size = int(data[-1])

            if status in status_codes:
                status_codes[status] += 1
            total_size += size

            if line_count % 10 == 0:
                print_logs()

        except (ValueError, IndexError):
            continue

except KeyboardInterrupt:
    print_logs()
    sys.exit(0)
