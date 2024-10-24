%define platform_id %(cat /etc/os-release | grep -w ID | cut -d '=' -f2)
%define version_id %(cat /etc/os-release | grep -w VERSION_ID | cut -d '=' -f2)

Name:       ru.ivars.rozhleys.notes
Summary:    Notes for Aurora OS
Version:    0.3.1
Release:    1
License:    BSD-3-Clause
URL:        https://gitlab.com/sven4500/aurora-notes
Source0:    %{name}-%{version}.tar.bz2

%if "%{platform_id}" == "auroraos"
BuildRequires:  pkgconfig(auroraapp)
%else
%if "%{platform_id}" == "sailfishos"
BuildRequires:  pkgconfig(sailfishapp)
%endif
%endif

Requires:   sailfishsilica-qt5 >= 0.10.9
#Requires:  qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer
#Requires:  qt5-qtmultimedia-plugin-mediaservice-gstmediacapture
#Requires:  qt5-qtdeclarative-import-multimedia
#Requires:  qt5-qtmultimedia
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)

%description
Application for keeping text, audio and visual notes for Aurora OS

%prep
%if "%{platform_id}" == "auroraos"
%autosetup
%else
%if "%{platform_id}" == "sailfishos"
%setup -q -n %{name}-%{version}
%endif
%endif

%build
%if "%{platform_id}" == "auroraos"
%cmake -DPLATFORM_ID=%{platform_id} -GNinja
%ninja_build
%else
%if "%{platform_id}" == "sailfishos"
%cmake -DPLATFORM_ID=%{platform_id}
%make_build
%endif
%endif

%install
%if "%{platform_id}" == "auroraos"
%ninja_install
%else
%if "%{platform_id}" == "sailfishos"
%make_install
%endif
%endif

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%defattr(644,root,root,-)
%{_datadir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
