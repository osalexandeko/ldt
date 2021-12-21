#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x306ff876, "module_layout" },
	{ 0x4896c53b, "cdev_del" },
	{ 0xbe1b7efd, "hrtimer_cancel" },
	{ 0xfe990052, "gpio_free" },
	{ 0x4848926, "hrtimer_init" },
	{ 0x313985dc, "device_destroy" },
	{ 0x3e04423, "cdev_add" },
	{ 0xde333c88, "cdev_init" },
	{ 0x9b15f0e8, "class_destroy" },
	{ 0x81d060cc, "device_create" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x84ca7a9e, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x25ea8b4b, "gpiod_direction_input" },
	{ 0x1624448b, "gpiod_export" },
	{ 0x95a7762c, "gpiod_direction_output_raw" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x5b94bd36, "hrtimer_start_range_ns" },
	{ 0x5f754e5a, "memset" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0x97255bdf, "strlen" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x86332725, "__stack_chk_fail" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xdff5b32b, "gpiod_get_raw_value" },
	{ 0xa381fa19, "kmalloc_caches" },
	{ 0xa3a5dfec, "kmem_cache_alloc_trace" },
	{ 0xc0025372, "hrtimer_forward" },
	{ 0x37a0cba, "kfree" },
	{ 0xc5850110, "printk" },
	{ 0xb14ac629, "gpiod_set_raw_value" },
	{ 0xf6ca1147, "gpio_to_desc" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "92FBECF4AAD7AAE28C1A418");
