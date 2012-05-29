void delay(int ms) {
struct timespec time;
time.tv_sec = ms / 1000;
time.tv_nsec = (ms % 1000) * (1000 * 1000);
nanosleep(&time,NULL);
}

void rdelay(int ms) {
refresh();
delay(ms);
}

