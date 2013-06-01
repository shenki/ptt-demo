/*
 * Joel Stanley <joel@jms.id.au>
 *
 * Licened under the GNU General Public License Version 3.
 * See http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * FT-817 Push-To-Talk CAT demo
 *
 */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

static const uint8_t ptt_on[] = {0x00, 0x00, 0x00, 0x00, 0x08};
static const uint8_t ptt_off[] = {0x00, 0x00, 0x00, 0x00, 0x88};

int main(int argc, char **argv)
{
    int portfd, r, speed;
    char *port;
    struct termios tty;

    if (argc != 2) {
        printf("usage: ptt [serial port path]\n");
        return -1;
    }
    port = argv[1];

    printf("FT-817 PTT Demo\n");

    printf("Opening %s\n", port);
    portfd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (portfd < 0) {
        perror(port);
        return -1;
    }
    printf("Setting speed to 38400.\n");
    if (tcgetattr(portfd, &tty) != 0) {
        perror("tcsetattr");
        return -1;
    }
    speed = B38400;
    cfsetospeed(&tty, speed);
    cfsetispeed(&tty, speed);
    if (tcsetattr(portfd, TCSANOW, &tty) != 0) {
        perror("tcsetattr");
        return -1;
    }

    printf("Press enter to PTT on...\n");
    getchar();

    r = write(portfd, ptt_on, sizeof(ptt_on));
    if (r < 0) {
        perror(port);
        return -1;
    }

    printf("Press enter to PTT off...\n");
    getchar();

    r = write(portfd, ptt_off, sizeof(ptt_off));
    if (r < 0) {
        perror(port);
        return -1;
    }

    return 0;
}
