Now that we have our library installed, we can get started playing around with our examples for each sensor. For the scope of this tutorial, we will combine the basic examples to output the values to a Serial Monitor. Then we will use the BME280 to compensate for the temperature and relative humidity. From there we will be able to build our own custom code to integrate the sensor into a project.



### Example 1: ENS160 and BME280 Combined Examples

Below is the combined example to read ENS160 and BME280. Copy and paste the code below in your Arduino IDE.

??? code "Example 1: ENS160 and BME280 Combined Examples"
    === "Ex1_Combined_Basic_Example_ENS160_BME280.ino"
        ``` c++ linenums="1"
        --8<-- "https://raw.githubusercontent.com/sparkfun/SparkFun_Environmental_Combo_Breakout_ENS160_BME280_QWIIC/main/Firmware/Ex1_Combined_Basic_Example_ENS160_BME280/Ex1_Combined_Basic_Example_ENS160_BME280.ino"
        ```

Select your board in the Tools menu (in our case **Arduino Uno**) and the correct Port it enumerated on and click "Upload". After uploading the code, open the [Serial Monitor](https://learn.sparkfun.com/tutorials/terminal-basics) or terminal emulator of your choice with the baud rate set to **115200**.



<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/Output_Arduino_Combined_Basic_Example_ENS160_BME280.JPG"><img src="../assets/img/Output_Arduino_Combined_Basic_Example_ENS160_BME280.JPG" height="600px" width="600px" alt="Combined Output Arduino ENS160 and BME280"></a></td>
    </tr>
  </table>
</div>


!!! note
    Note that the ENS160 needs some time to calculate values as stated in the datasheet on page 15 and 16 before the measurements are reasonable. Try moving the `ensStatus` into the loop to monitor the reliability of the ENS160's output.

    #### Initial Start-Up

    <quote>Initial Start-Up is the time the ENS160 needs to exhibit reasonable air quality readings after its first ever power-on.

    The ENS160 sensor raw resistance signals and sensitivities will change upon first power-on. The change in resistance is greatest in the first 48 hours of operation. Therefore, the ENS160 employs a start-up algorithm, allowing eCO2, TVOC and AQI output signals to be used from first power-on after 1 hour of operation.</quote>

    #### Initial Warm-Up

    <quote>Further to “Initial Start-up” the conditioning or “Warm-up” period is the time required to achieve adequate sensor stability before measuring VOCs after idle periods or power-off. Typically, the ENS160 requires 3 minutes of warm-up until reasonable air quality readings can be expected.</quote>



### Example 2: Combined Basic Example ENS160/BME280 in CSV Format

Below is the same combined code but formatted for CSV. Copy and paste the code below in your Arduino IDE.

??? code "Example 2: Combined Basic Example ENS160/BME280 in CSV Format"
    === "Ex2_Combined_Basic_Example_ENS160_BME280_CSV.ino"
        ``` c++ linenums="1"
        --8<-- "https://raw.githubusercontent.com/sparkfun/SparkFun_Environmental_Combo_Breakout_ENS160_BME280_QWIIC/main/Firmware/Ex2_Combined_Basic_Example_ENS160_BME280_CSV/Ex2_Combined_Basic_Example_ENS160_BME280_CSV.ino"
        ```

Select your board in the Tools menu (in our case **Arduino Uno**) and the correct Port it enumerated on and click "Upload". After uploading the code, open the [Serial Monitor](https://learn.sparkfun.com/tutorials/terminal-basics) or terminal emulator of your choice with the baud rate set to **115200**.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/Output_Arduino_Combined_Basic_Example_ENS160_BME280_CSV.JPG"><img src="../assets/img/Output_Arduino_Combined_Basic_Example_ENS160_BME280_CSV.JPG" height="600px" width="600px" alt="Combined Output Arduino ENS160 and BME280 in CSV"></a></td>
    </tr>
  </table>
</div>



### Example 3: BME280 Temperature and Relative Humidity Compensation

!!! note
    This example is actually in the ENS160 Arduino Library! [It is listed as example 4](https://github.com/sparkfun/SparkFun_Indoor_Air_Quality_Sensor-ENS160_Arduino_Library/blob/main/examples/example4_BME280_temp_rh_compensation/example4_BME280_temp_rh_compensation.ino) even though in this tutorial we are referring to it as "example 3."

The example code below uses the BME280 for temperature and relative humidity compensation when reading values from the ENS160. Copy and paste the code below in your Arduino IDE.

??? code "Example 3: BME280 Temperature and Relative Humidity Compensation"
    === "example4_BME280_temp_rh_compensation.ino"
        ``` c++ linenums="1"
        --8<-- "https://raw.githubusercontent.com/sparkfun/SparkFun_Indoor_Air_Quality_Sensor-ENS160_Arduino_Library/main/examples/example4_BME280_temp_rh_compensation/example4_BME280_temp_rh_compensation.ino"
        ```

Select your board in the Tools menu (in our case **Arduino Uno**) and the correct Port it enumerated on and click "Upload". After uploading the code, open the [Serial Monitor](https://learn.sparkfun.com/tutorials/terminal-basics) or terminal emulator of your choice with the baud rate set to **115200**.

<div style="text-align: center;">
  <table>
    <tr style="vertical-align:middle;">
     <td style="text-align: center; vertical-align: middle;"><a href="../assets/img/Output_Arduino_BME280_Temperature_Relative_Humidity_Compensation_Air_Quality_Sensor_ENS160.JPG"><img src="../assets/img/Output_Arduino_BME280_Temperature_Relative_Humidity_Compensation_Air_Quality_Sensor_ENS160.JPG" height="600px" width="600px" alt="Output Arduino BME280 Temperature and Humidity Compensated Air Quality Sensor ENS160"></a></td>
    </tr>
  </table>
</div>



### More Examples!!!

Make sure to check the Arduino Libraries that you installed on your computer for more examples with the ENS160 and BME280! Remember, the SPI port is not broken out on the Environmental Combo Breakout - ENS160/BME280 so those examples will not apply for this specific board.

<div style="text-align: center">
    <a href="https://github.com/sparkfun/SparkFun_Indoor_Air_Quality_Sensor-ENS160_Arduino_Library/tree/main/examples" class="md-button">GitHub SparkFun > SparkFun_Indoor_Air_Quality_Sensor-ENS160_Arduino_Library > Examples</a>
    <br /><br />
    <a href="https://github.com/sparkfun/SparkFun_BME280_Arduino_Library/tree/master/examples" class="md-button md-button">GitHub SparkFun > SparkFun_BME280_Arduino_Library > Examples</a></div>
