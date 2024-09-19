Name:       ru.ivars.rozhleys.notes
Summary:    Notes for Aurora OS
Version:    0.2.0
Release:    1
License:    BSD-3-Clause
URL:        https://gitlab.com/sven4500/aurora-notes
Source0:    %{name}-%{version}.tar.bz2

Requires:   sailfishsilica-qt5 >= 0.10.9
#Requires:  qt5-qtmultimedia-plugin-mediaservice-gstmediaplayer
#Requires:  qt5-qtmultimedia-plugin-mediaservice-gstmediacapture
#Requires:  qt5-qtdeclarative-import-multimedia
#Requires:  qt5-qtmultimedia
BuildRequires:  pkgconfig(auroraapp)
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5Qml)
BuildRequires:  pkgconfig(Qt5Quick)

%description
Application for keeping text, audio and visual notes for Aurora OS

%prep
%autosetup

%build
%cmake -GNinja
%ninja_build

%install
%ninja_install

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%defattr(644,root,root,-)
%{_datadir}/%{name}
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}.png
