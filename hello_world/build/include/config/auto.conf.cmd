deps_config := \
	/home/kurodyt/esp/esp-idf/components/aws_iot/Kconfig \
	/home/kurodyt/esp/esp-idf/components/bt/Kconfig \
	/home/kurodyt/esp/esp-idf/components/esp32/Kconfig \
	/home/kurodyt/esp/esp-idf/components/ethernet/Kconfig \
	/home/kurodyt/esp/esp-idf/components/fatfs/Kconfig \
	/home/kurodyt/esp/esp-idf/components/freertos/Kconfig \
	/home/kurodyt/esp/esp-idf/components/log/Kconfig \
	/home/kurodyt/esp/esp-idf/components/lwip/Kconfig \
	/home/kurodyt/esp/esp-idf/components/mbedtls/Kconfig \
	/home/kurodyt/esp/esp-idf/components/openssl/Kconfig \
	/home/kurodyt/esp/esp-idf/components/spi_flash/Kconfig \
	/home/kurodyt/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/kurodyt/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/kurodyt/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/kurodyt/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
