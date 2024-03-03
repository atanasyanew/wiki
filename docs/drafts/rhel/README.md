# Red Hat Enterprise Linux 101

*Modified 2024-03-03*

!> Work in process!

- [Red Hat Enterprise Linux 101](#red-hat-enterprise-linux-101)
  - [RHEL getting started](#rhel-getting-started)
  - [RHEL Essentials](#rhel-essentials)
  - [Built-in tools](#built-in-tools)
  - [Containers](#containers)
  - [Further explore](#further-explore)
  - [Author notes](#author-notes)


## RHEL getting started

The default package manager is ``YUM`` (Yellowdog Updater, Modified), whereas in ``Ubuntu``,  the default package manager is ``APT`` (Advanced Package Tool).

To install packages in RHEL using YUM
```bash
sudo yum install package-name
```

To update packages in ``RHEL``, you can use the following command:
```bash
sudo yum update
```
This will update all installed packages to their latest versions.

It's important to note that the syntax and options for ``YUM`` are different from those of ``APT``, so you'll need to familiarize yourself with the ``YUM`` commands and options if you're used to using ``APT`` on ``Ubuntu``.  
In addition to ``YUM``, ``RHEL`` also includes the package management tool ``DNF`` (Dandified YUM), which is similar to ``YUM`` but includes some additional features and improvements.  
You may want to consider using ``DNF`` instead of ``YUM`` if you're starting from scratch with ``RHEL``, as it is the default package manager in ``RHEL`` 8 and later.  
The commands for ``DNF`` are similar to those for ``YUM``, but with some differences in syntax and options.

- To install a package, use the following command:
```bash
sudo dnf install package-name
```
This will download and install the specified package and any dependencies it requires.

- To remove a package, use the following command:
```bash
sudo dnf remove package-name
```
This will remove the specified package and any packages that depend on it.

- To update all packages, use the following command:
```bash
sudo dnf update
```
This will download and install the latest versions of all installed packages.

- To search for a package, use the following command:
```bash
sudo dnf search search-term
```
This will search for packages that match the specified search term in their name or description.

- To check for available updates, use the following command:
```bash
sudo dnf check-update
```
This will check for updates to all installed packages and display a list of the packages that have updates available.

- To list all installed packages, use the following command:
```bash
sudo dnf list installed
```
This will display a list of all packages that are currently installed on your system.

- To clean up the local cache of downloaded package files, use the following command:
```bash
sudo dnf clean all
```
This will remove all cached package files from the system to free up disk space.

## RHEL Essentials

- Repositories: ``DNF`` uses repositories to download packages and updates. By default, ``RHEL`` is configured with a set of repositories that include a base repository, an updates repository, and several others. You can also add third-party repositories to ``DNF`` by adding configuration files to the ``/etc/yum.repos.d/`` directory. Make sure to check that the repositories you are using are trustworthy and compatible with your version of ``RHEL``.

- System updates: It's important to keep your ``RHEL`` system up to date with the latest security patches and bug fixes. You can use the dnf update command to update all installed packages to their latest versions. It's a good idea to check for updates regularly and apply them as soon as possible.

- Security: ``RHEL`` is known for its strong security features, but it's still important to take additional steps to secure your system. You can use tools like ``SELinux`` (Security-Enhanced Linux) to further protect your system from malicious activity. Make sure to also use strong passwords, configure a firewall, and disable unnecessary services to reduce your attack surface.

- Package management: ``DNF`` provides many features for managing packages and dependencies, including automatic resolution of dependencies, rollback of updates, and more. Make sure to read the ``DNF documentation`` to understand how these features work and how to use them effectively.

- Support: If you run into issues with your ``RHEL`` installation or have questions about how to use ``DNF``, you can contact Red Hat support for assistance. Keep in mind that support for ``RHEL`` requires a subscription, so make sure to have a subscription in place before you need support.

Overall, switching from ``Ubuntu`` to ``RHEL`` can be a great choice for your home servers, but it does require some learning and adjustment. By familiarizing yourself with the tools and best practices for ``RHEL`` and ``DNF``, you can get the most out of your new setup and enjoy the stability and security benefits of this popular distribution.

## Built-in tools

RHEL includes several tools out of the box that you can use to monitor your system's performance and resource usage. Here are a few that you may find useful:

- ``GNOME System Monitor``: This is a graphical tool that allows you to monitor your system's CPU, memory, and network usage, as well as view running processes and their resource usage. To launch the GNOME System Monitor, you can open the Activities menu and search for "System Monitor", or you can run the ``gnome-system-monitor`` command in the terminal.

- ``Top``: This is a command-line utility that provides real-time information about the processes running on your system and their resource usage, including CPU and memory usage. To launch top, you can open the terminal and run the top command.

- ``sar``: This is a command-line utility that collects and reports system activity data, such as CPU and memory usage, disk activity, and network activity. To use ``sar``, you need to install the sysstat package first by running sudo dnf install sysstat and then you can run the sar command to get the system activity data.

- ``dmesg``: This is a command-line utility that displays kernel messages related to system events, such as hardware detection, software errors, and other system events. To launch ``dmesg``, you can open the terminal and run the ``dmesg`` command.

- ``Cockpit``. ``RHEL`` includes a web-based system monitoring tool called ``Cockpit``. User-friendly, web-based interface that provides a real-time, graphical overview of your system's performance, as well as tools for managing services, storage, and networking.  
To use Cockpit, you'll need to enable it first if it's not already enabled on your system.  You can do this by running the following command in the terminal:
```bash
sudo systemctl enable --now cockpit.socket
```
This command will enable and start the Cockpit service on your system.  
Once ``Cockpit`` is running, you can access it by opening a web browser and navigating to ``https://<your-server-ip>:9090``.  
You'll be prompted to log in with your system username and password.  
Once you're logged in, you can use ``Cockpit`` to monitor your system's ``CPU``, ``memory``, and ``network`` usage, as well as view running processes and their resource usage.  
You can also use ``Cockpit`` to manage ``services``, ``storage``, and ``networking``.  

These tools should give you a good starting point for monitoring your system's performance and resource usage. You may also want to consider using additional tools, such as ``Nagios`` or ``Zabbix``, for more comprehensive monitoring and alerting.

## Containers

``Podman`` is a container engine that allows you to run and manage containers on your ``RHEL`` system.  
It is similar to ``Docker``, but with a few key differences.  
One of the main differences between ``Podman`` and ``Docker`` is that ``Podman`` does not require a daemon to be running in the background to manage containers.  
Instead, each container runs in its own individual process on the host system.  
This makes ``Podman`` more lightweight and secure than ``Docker``, since it does not require a privileged daemon process to be running on the host system.  
``Podman`` is included with ``RHEL`` and can be managed using the podman command-line tool.  With ``Podman``, you can create and manage containers, build container images, and distribute container images to other systems.  

In ``Cockpit``, the ``Podman`` menu allows you to manage containers and container images using a web-based interface.  
You can use ``Cockpit`` to start and stop containers, view container logs and resource usage, and manage container networks and storage.

Overall, ``Podman`` is a powerful tool for managing containers on your ``RHEL`` system, and ``Cockpit`` provides a user-friendly way to manage and monitor containers using a web interface.  

**Docker to Podman**  
You can use the same ``docker-compose`` files with ``Podman`` that you use with ``Docker``.  
``Podman`` supports a ``docker-compose`` compatible command-line tool called ``podman-compose`` that allows you to manage multi-container applications using ``docker-compose`` files.
To use ``podman-compose``, you will first need to install it on your ``RHEL`` system.  
You can do this by running the following command in the terminal:
```bash
sudo dnf install podman-compose
```
Once ``podman-compose`` is installed, you can use it to manage multi-container applications using ``docker-compose`` files.  
The syntax for ``podman-compose`` is similar to that of ``docker-compose``, so you should be able to use the same ``docker-compose.yml`` file with podman-compose that you use with ``Docker``.  
For example, to start a multi-container application using podman-compose, you can navigate to the directory containing your ``docker-compose.yml`` file and run the following command:
```bash
podman-compose up -d
```
This will start all of the containers defined in the ``docker-compose.yml`` file in detached mode.  
Note that while ``Podman`` is designed to be compatible with ``Docker``, there may be some differences in behavior between the two tools.  
It's always a good idea to test your ``docker-compose`` files with ``Podman`` to ensure that they work as expected.

## Further explore

Here are a few additional suggestions for things you might want to check out as you continue to explore RHEL:

- ``SELinux``: ``RHEL`` includes a powerful security feature called ``SELinux``, which provides an additional layer of security by enforcing mandatory access controls on system resources. 
- ``Firewalld``: ``RHEL`` uses a firewall management tool called ``Firewalld``, which provides a simple interface for managing firewall rules. 
- ``Red Hat Subscription Manager``: ``RHEL`` is a commercial product that requires a subscription to access updates and support. Red Hat Subscription Manager is a tool that allows you to manage your ``RHEL`` subscriptions and keep your system up to date.
- ``Red Hat Developer Tools``: If you're a developer, you might be interested in the suite of development tools that Red Hat provides for ``RHEL``, including programming languages, compilers, and libraries. You might want to check out the Red Hat Developer Tools website to learn more about these tools and how to use them.

Overall, there are many aspects of ``RHEL`` that you can explore and learn about as you continue to use it.

## Author notes

```bash
install podman compose
# enable from web UI
sudo dnf install epel-release
sudo subscription-manager repos --enable codeready-builder-for-rhel-9-x86_64-rpms
sudo dnf install python36
sudo dnf install podman-compose
```

Proxmox VM:
- when create vm in proxmox cpu must be type ``Host`` to avoid kernel panic
- In network apply host name ``infra``
- select software packages, include guest aganet and containers
- config users and credentials

[Chapter 10. Setting up a WireGuard VPN](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/9/html/configuring_and_managing_networking/assembly_setting-up-a-wireguard-vpn_configuring-and-managing-networking) 
