#include <zephyr/device.h>
#include <zephyr/drivers/sensor.h>

int main(){
    printk("ODSL8 sample application\n");

    const device *my_sensor = DEVICE_DT_GET(DT_NODELABEL(my_sensor));

    if (!device_is_ready(my_sensor)) {
		printk("my_sensor: device not ready.\n");
		return 0;
	}

    while (true) {        
        sensor_sample_fetch(my_sensor);
        sensor_value my_value{};
        sensor_channel_get(my_sensor, SENSOR_CHAN_DISTANCE, &my_value);
		printk("odsl8 distance: %f\n", sensor_value_to_double(&my_value));
    }
}
